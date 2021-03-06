#ifndef __itkMultiThreadedImageFilter_hxx
#define __itkMultiThreadedImageFilter_hxx

#include "MultiThreadedImageFilter.h"

#include "itkObjectFactory.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIterator.h"

namespace itk
{

template< class TImage>
void MultiThreadedImageFilter< TImage>
::ThreadedGenerateData(const OutputImageRegionType & region, ThreadIdType threadId)
{
  std::cout << "Thread " << threadId << " given region: " << region << std::endl;

  typename TImage::ConstPointer input = this->GetInput();
  typename TImage::Pointer output = this->GetOutput();

  ImageAlgorithm::Copy(input.GetPointer(), output.GetPointer(), region,
                       region);

  itk::Index<2> cornerPixel = region.GetIndex();
  std::cout << "cornerPixel: " << cornerPixel << std::endl;
  typename TImage::PixelType newValue = 3;

  output->SetPixel( cornerPixel, newValue );
}

}// end namespace


#endif
