
namespace lasd {

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& CopyStruct){
        bool allcopied = true;

        CopyStruct.Traverse(

            [this, &allcopied](const Data& pastdata){
                allcopied &= this->Insert(pastdata);
            }
        );

        return allcopied;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& MoveStruct){
        bool allmoved = true;

        MoveStruct.Map(

            [this, &allmoved](Data& pastdata){
                allmoved &= this->Insert(std::move(pastdata));
            }
        );

        return allmoved;

    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> & RemoveStruct){
        bool allremoved = true;

        RemoveStruct.Traverse(

            [this, &allremoved](const Data& pastdata){
                allremoved &= this->Remove(pastdata);
            }
        );

        return allremoved;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> & CopyStruct){
        bool somecopied = false;

        CopyStruct.Traverse(

            [this, &somemoved](const Data& pastdata){
                somemoved |= this->Insert(pastdata);
            }
        );

        return somecopied;

    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& MoveStruct){
        bool somemoved = false;
        
        MoveStruct.Map(

            [this, &somemoved](Data& pastadata){
                somemoved |= this->Insert(std::move(pastadata));
            }
        );

        return somemoved;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& RemoveStruct){
        bool someremoved = false;

        RemoveStruct.Traverse(

            [this, &someremoved](const Data& pastdata){
                someremoved |= this->Remove(pastdata);
            }
        );

        return someremoved;
    }

}




