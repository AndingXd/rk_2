#include <iostream>

class AbstractVisitor
{
 public:
   virtual ~AbstractVisitor() = default;
};


template< typename T >
class Visitor
{
 protected:
   virtual ~Visitor() = default;

 public:
   virtual void visit( T const& ) const = 0;
};



class Shape
{
 public:
   virtual ~Shape() = default;

   virtual void accept( AbstractVisitor const& v ) = 0;
};

class Circle : public Shape
{
 public:
   explicit Circle( double radius )
      : radius_( radius )
   {
      /* Checking that the given radius is valid */
   }

   void accept( AbstractVisitor const& v ) override {
      if( auto const* cv = dynamic_cast<Visitor<Circle> const*>(&v) ) {
         cv->visit(*this);
      }
   }

   double radius() const { return radius_; }

 private:
   double radius_;
};


class Square : public Shape
{
 public:
   explicit Square( double side )
      : side_( side )
   {
      /* Checking that the given side length is valid */
   }

   void accept( AbstractVisitor const& v ) override {
      if( auto const* sv = dynamic_cast<Visitor<Square> const*>(&v) ) {
         sv->visit(*this);
      }
   }

   double side() const { return side_; }

 private:
   double side_;
};


class Draw : public AbstractVisitor
           , public Visitor<Circle>
           , public Visitor<Square>
{
 public:
   void visit( Circle const& c ) const override
      { /* ... Implementing the logic for drawing a circle ... */ }
   void visit( Square const& s ) const override
      { /* ... Implementing the logic for drawing a square ... */ }
};

#include <memory>
#include <vector>
class Shape;

void drawAllShapes( std::vector< std::unique_ptr<Shape> > const& shapes );


void drawAllShapes( std::vector< std::unique_ptr<Shape> > const& shapes )
{
   for( auto const& shape : shapes )
   {
      shape->accept( Draw{} );
   }
}
