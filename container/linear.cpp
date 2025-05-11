
namespace lasd {

    template <typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& dato) const noexcept{
        if(size != dato.size ){
            return false;
        }

        for(unsigned long  i = 0; i < size ; i++){
            if(this->operator[](i) != dato[i]){
                return false;
            }    
        }

        return true;
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& dato) const noexcept{
        return !(operator==(dato));
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Front() const{
        if(size != 0){
            return this->operator[](0);
        }
        else{
            throw std::lenght_error("LinearContainer Vuoto");
        }
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Front(){
        if(size != 0){
            return this->operator[](0);
        }
        else{
            throw std::lenght_error("LinearContainer Vuoto");
        }
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Back() const{
        if(size != 0){
            return this->operator[](Container::size-1);
        }
        else{
            throw std::lenght_error("LinearContainer Vuoto");
        }
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back(){
        if(size != 0){
            return this->operator[](Container::size-1);
        }
        else{
            throw std::lenght_error("LinearContainer Vuoto");
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun function) const{
        for(unsigned long int i = 0; i < size; i++){
            function(this->operator[](i));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun function) const{
        unsigned long int i = size;
        while(i > 0){
            function(this->operator[](i--));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::Map(MapFun function){
        PreOrderMap(function);
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(Traverse function) const{
        PreOrderTraverse(function);
    }

      template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFun function){
        for(unsigned long int i = 0; i < Container::size; i++){
            function(this->operator[](i));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun function){
        unsigned long int i = Container::size;
        while(i > 0){
            function(this->operator[](--i));
        }
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& dato) const noexcept{
        return LinearContainer<Data>::operator==(dato);
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& dato) const noexcept{
        return !(operator==(dato));
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::Partition(unsigned long int lt, unsigned long int rt) noexcept{
        Data x = this->operator[](p);
        unsigned long int i = lt - 1;
        unsigned long int j = rt + 1;

        do{

            do{j--;} while(x < this->operator[](j));

            do{i++;} while(this->operator[](i) < x);

            if(i < j){
                std::swap(this->operator[](i),this->operator[](j));
            }
        }while(i < j)

        return j;
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(unsigned long int lt, unsigned long rt) noexcept{
        if(lt < rt){
            unsigned long int q = Partition(lt, rt);
            QuickSort(lt, rt);
            QuickSort(q + 1, lt);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept{
        QuickSort(0, size - 1);
    }
}
