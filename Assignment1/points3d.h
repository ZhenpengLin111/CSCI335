// --> Zhenpeng Lin
// Few comments describing the class Points3D

#ifndef CSCI335_HOMEWORK1_POINTS3D_H_
#define CSCI335_HOMEWORK1_POINTS3D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points3D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points3D() 
    {
        sequence_ = nullptr;
        size_ = 0;
    }

    // Copy-constructor.
    Points3D(const Points3D &rhs)
    {
        sequence_ = new std::array<Object, 3>[rhs.size_];
        size_ = rhs.size_;
        for(size_t i=0; i<rhs.size_; i++)
        {
            sequence_[i][0] = rhs.sequence_[i][0];
            sequence_[i][1] = rhs.sequence_[i][1];
            sequence_[i][2] = rhs.sequence_[i][2];
        }

    }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points3D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points3D& operator=(const Points3D &rhs)
    {
        Points3D copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // Move-constructor.
    Points3D(Points3D &&rhs)
    {
        sequence_ = rhs.sequence_;
        size_ = rhs.size_;
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points3D& operator=(Points3D &&rhs)
    {
        std::swap(sequence_, rhs.sequence_);
        std::swap(size_, rhs.size_);
        return *this;
    }

    ~Points3D()
    {
        delete sequence_;
        size_ = 0;
    }

    // End of big-five.

    // One parameter constructor.
    Points3D(const std::array<Object, 3>& item) {
        sequence_ = new std::array<Object, 3>[1];
        size_ = 1;
        sequence_[0][0] = item[0];
        sequence_[0][1] = item[1];
        sequence_[0][2] = item[2];
        // Provide code.
    }

    size_t size() const {
        return size_;
        // Code missing.
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 3>& operator[](size_t location) const {
        if(location < 0 || location > size_)
        {
            abort();
        }
        else{
            return sequence_[location];
        }
        // Code missing.
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points3D operator+(const Points3D &c1, const Points3D &c2) {
        size_t bigger_size = 0;
        size_t smaller_size = 0;
        if(c1.size_ > c2.size_)
        {
            bigger_size = c1.size_;
            smaller_size = c2.size_;
        }
        else{
            bigger_size = c2.size_;
            smaller_size = c1.size_;
        }

        Points3D sum;
        sum.sequence_ = new std::array<Object, 3>[bigger_size];
        sum.size_ = bigger_size;
        
        for(size_t i=0; i<smaller_size; i++)
        {
            sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
            sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
            sum.sequence_[i][2] = c1.sequence_[i][2] + c2.sequence_[i][2];
        }

        if(c1.size_ > c2.size_)
        {
            for(size_t i=smaller_size; i<bigger_size; i++)
            {
                sum.sequence_[i][0] = c1.sequence_[i][0];
                sum.sequence_[i][1] = c1.sequence_[i][1];
                sum.sequence_[i][2] = c1.sequence_[i][2];
            }
        }
        else if(c2.size_ > c1.size_) {
            for(size_t i=smaller_size; i<bigger_size; i++)
            {
                sum.sequence_[i][0] = c2.sequence_[i][0];
                sum.sequence_[i][1] = c2.sequence_[i][1];
                sum.sequence_[i][2] = c2.sequence_[i][2];
            }
        }
        return sum;
        // Code missing.
    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points3D &some_points) {
        if(some_points.size_ == 0)
        {
            out << "()" <<std::endl;
        }
        else{
            for(size_t i=0; i<some_points.size_; i++)
            {
                out << "(" << some_points[i][0] << ", " << some_points[i][1] << ", " << some_points[i][2] << ") ";
            }
            out << std::endl;
        }
        return out;
        // Code missing.
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points3D &some_points) {
        std::cout << std::endl;
        in >> some_points.size_;
        some_points.sequence_ = new std::array<Object, 3>[some_points.size_];

        for(size_t i=0; i<some_points.size_; i++)
        {
            for(size_t j=0; j<3; j++)
            {
                in >> some_points.sequence_[i][j];
            }
        }
            
        return in;
        // Code missing.
    }

  private:
    // Sequence of points.
    std::array<Object, 3> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS3D_H_