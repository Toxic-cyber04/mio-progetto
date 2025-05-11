
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~TestableContainer() specifiers
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  virtual TestableContainer& operator=(const TestableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual TestableContainer& operator=(TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator==(const TestableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator!=(const TestableContainer&) const noexcept = delete;

  // Da capire perchè adesso ho aggiunto a tutti virtual !!!

  /* ************************************************************************ */

  // Specific member function

  // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
  
  inline virtual bool Exists(const Data&) const noexcept = 0; //Dev'essere implementata dall'erede, virtual puro
      
  

};

/* ************************************************************************** */

}

#endif
