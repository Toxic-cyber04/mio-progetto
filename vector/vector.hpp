
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public MutableLinearContainer<Data>, virtual public ResizableContainer{
  // Must extend MutableLinearContainer<Data>,
  //             ResizableContainer

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  // ...
  Data* elementi = nullptr;

public:

  // Default constructor
  // Vector() specifiers;
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  Vector(unsigned long int num){
    size = num;
    elementi = new Data[num]();
  }
  // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
  inline Vector(const TraversableContainer<Data> & );
  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  inline Vector(MappableContainer<Data> && );

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;
  inline Vector(const Vector<Data> & );

  // Move constructor
  // Vector(argument) specifiers;
  inline Vector(Vector<Data> && ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;
  virtual ~Vector(){
    delete[] elementi;
  }

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline Vector<Data>& operator=(const Vector<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;
  inline Vector<Data>& operator=(Vector<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const Vector<Data> &) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const Vector<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)
  inline const Data& operator[](unsigned long int) const override;

  inline Data& operator[](unsigned long int) override;

  // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
  inline const Data& Front() const override;

  inline Data& Front() override;

  // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
  inline const Data& Back() const override;

  inline Data& Back() override;

  inline virtual void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
  inline virtual const Data& operator[](const unsigned long int) const override;

  inline virtual Data& operator[](const unsigned long int) override;

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  inline virtual const Data& Front() const override;

  inline virtual Data& Front() override;


  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  inline virtual const Data& Back() const override;

  inline virtual Data& Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  inline virtual void Resize (const unsigned long) override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override; 

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data>, virtual public SortableLinearContainer<Data>{
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  // ...

public:

  // Default constructor
  // SortableVector() specifiers;
  SortableVector() = default;

  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; // A vector with a given initial dimension
  inline SortableVector(unsigned long num) : Vector<Data>::Vector(num){};
  // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  inline SortableVector(const TraversableContainer<Data> & struttura) : Vector<Data>::Vector(struttura){};
  // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer
  inline SortableVector(MappableContainer<Data> && struttura) : Vector<Data>::Vector(std::move(struttura)){};

  /* ************************************************************************ */

  // Copy constructor
  // SortableVector(argument) specifiers;
  inline SortableVector (const SortableVector<Data> & vet) : Vector<Data>::Vector(vet){};

  // Move constructor
  // SortableVector(argument) specifiers;
  inline SortableVector(SortableVector<Data> && vet) noexcept : Vector<Data>::Vector(std::move(vet)){};

  /* ************************************************************************ */

  // Destructor
  // ~SortableVector() specifiers;
  virtual ~SortableVector() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline SortableVector<Data>& operator=(const SortableVector<Data> & vet);

  // Move assignment
  // type operator=(argument) specifiers;
  inline SortableVector<Data>& operator=(SortableVector<Data>&& vet) noexcept;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
