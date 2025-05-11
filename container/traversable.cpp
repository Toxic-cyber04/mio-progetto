
namespace lasd {

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data& findvalue) const noexcept{
        bool exist = false;

        Traverse(
            [findvalue, &exist](const Data& pastdata){
                exist |= (pastadata == findvalue);
            }
        );

        return exist;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> function, Accumulator base) const{

        Traverse(
            [&base, function](const Data& pastdata){
                base = function(pastdata, base);
            }
        );

        return base;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> function, Accumulator base) const{

        PreOrderTraverse(
            [function, &base](const Data& pastdata){
                base = function(pastdata, base);
            }
        );

        return base;
    }


    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> function, Accumulator base) const{

        PostOrderTraverse(
            [function, &base](const Data& pastdata){
                base = function(pastdata, base);
            }
        );

        return base;
    }


    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun function) const{
        PreOrderTraverse(function);
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun function) const{
        PostOrderTraverse(function);
    }
}
