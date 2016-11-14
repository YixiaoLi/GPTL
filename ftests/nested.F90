program nested
  integer :: i, j
  integer :: ret
  integer :: iter

  ret = GPTLinitialize ()

  call omp_set_nested (.true.) ! Enable nested OMP
  do iter=1,10
!$omp parallel do
    do j=1,3
!$omp parallel do private (ret)
      do i=1,2
	ret = GPTLstart ("nested")
        ret = GPTLstop ("nested")
      end do
!$omp end parallel do
    end do
!$omp end parallel do
  end do
  ret = GPTLpr (0);
  stop
end program nested
