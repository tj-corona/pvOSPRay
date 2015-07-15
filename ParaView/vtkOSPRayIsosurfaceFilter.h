/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOSPRayIsosurfaceFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkOSPRayIsosurfaceFilter - generate scalars along a specified direction
// .SECTION Description
// vtkOSPRayIsosurfaceFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef __vtkOSPRayIsosurfaceFilter_h
#define __vtkOSPRayIsosurfaceFilter_h

#include "vtkFiltersCoreModule.h"
#include "vtkDataSetAlgorithm.h"
#include "vtkElevationFilter.h"



class VTK_EXPORT vtkOSPRayIsosurfaceFilter : public vtkElevationFilter
{
public:
  static vtkOSPRayIsosurfaceFilter* New();
  vtkTypeMacro(vtkOSPRayIsosurfaceFilter, vtkElevationFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

    vtkGetMacro(ClipValue, double);
  vtkSetMacro(ClipValue, double);

    vtkGetMacro(EnableClip, bool);
  vtkSetMacro(EnableClip, bool);

      vtkGetMacro(ClipAxis, int);
  vtkSetMacro(ClipAxis, int);

  void SetValue(int i, double val);
  double GetVale(int i)
  {
    return ContourValues[i];
  }

  void SetNumberOfContours(int number)
  {
    NumberOfContours=number;
  }
  int GetNumberOfContours()
  { return NumberOfContours; }




protected:
  vtkOSPRayIsosurfaceFilter();
  ~vtkOSPRayIsosurfaceFilter();

    int RequestData(vtkInformation*,
                  vtkInformationVector**,
                  vtkInformationVector*);

    int NumberOfContours;
    double ContourValues[256];  
    double ClipValue;
    bool EnableClip;
    int ClipAxis;

private:
  vtkOSPRayIsosurfaceFilter(const vtkOSPRayIsosurfaceFilter&);  // Not implemented.
  void operator=(const vtkOSPRayIsosurfaceFilter&);  // Not implemented.
};

#endif
