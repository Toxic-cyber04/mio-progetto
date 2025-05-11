
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public MutableLinearContainer<Data>, virtual public ClearableContainer{
  // Must extend MutableLinearContainer<Data>,
  //             ClearableContainer

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  struct Node {

    // Data
    // ...
    Data element{};
    Node *next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    // ...
    inline Node() = default;
    /* ********************************************************************** */

    // Copy constructor
    // ...
    inline Node(const Data& dato) : element{dato} {}

    // Move constructor
    // ...
    inline Node(Data&& dato) noexcept{
      std::swap(element,dato);
    }

    /* ********************************************************************** */

    // Destructor
    // ...
    virtual ~Node(){
      delete next;
    }

    /* ********************************************************************** */

    // Comparison operators
    // ...
    inline bool operator==(const Node & nodo) const noexcept{
      return element == nodo.element;
    }

    inline bool operator!=(const Node & nodo) const noexcept{
      return !operator==(nodo);
    }

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  Node *head = nullptr;
  Node *tail = nullptr;

  // ...

public:

  // Default constructor
  // List() specifiers;
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  inline List(const TraversableContainer<Data> &);
  // List(argument) specifiers; // A list obtained from a MappableContainer
  inline List(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  inline List(const List&);

  // Move constructor
  // List(argument) specifiers;
  inline List(List &&);

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
  virtual ~List();


  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline List& operator=(const List&);

  // Move assignment
  // type operator=(argument) specifiers;
  inline List& operator=(List &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const List&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  inline void InsertAtFront(const Data&);
  // type InsertAtFront(argument) specifier; // Move of the value
  inline void InsertAtFront(Data&&);
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  inline void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  inline Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  inline void InsertAtBack(const Data&);
  // type InsertAtBack(argument) specifier; // Move of the value
  inline void InsertAtBack(Data&&);
  // type RemoveFromBack() specifier; // (must throw std::length_error when empty)
  inline void RemoveFromBack();
  // type BackNRemove() specifier; // (must throw std::length_error when empty)
  inline Data BackNRemove();

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

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
  inline const Data& operator[](unsigned long) const override;

  inline Data& operator[](unsigned long) override;

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  inline const Data& Front() const override;

  inline Data& Front() override;

  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  inline const Data& Back() const override;

  inline Data& Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFun) override;


  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
  inline void PreOrderTraverse(TraverseFun) const override;

  inline void PreOrderTraverse(TraverseFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
  inline void PostOrderTraverse(TraverseFun) const override;



  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  inline void Clear() override;

protected:
  // Auxiliary functions, if necessary!
  inline void PreOrderTraverse(TraverseFun, Node*) const;
  inline void PostOrderTraverse(TraverseFun, Node*) const;
  inline void PreOrderMap(MapFun, Node*);
  inline void PostOrderMap(MapFun, Node*);

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
