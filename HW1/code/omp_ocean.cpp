
void evenStep(int *grid, int xdim, int ydim) {
    #pragma omp parallel for private(grid, xdim, ydim)
	for (int i=1; i<xdim-1; i++) {
		for (int j=1+i%2; j<ydim-1; j+=2) {
			//printf("Computing location (%d, %d) = %d\n", i, j, j*xdim+i);
			//cout << "Computing for location (" << j << "," << i << ")(" << i*(ydim)+j << ") = " << grid[i*(ydim)+j] << endl;
			int n = grid[(i-1)*(ydim)+j];
			int e = grid[i*(ydim)+j+1];
			int s = grid[(i+1)*(ydim)+j];
			int w = grid[i*(ydim)+j-1];
			int m = grid[i*(ydim)+j];
			m = (n+e+s+w+m)/5;
			//cout << "n: " << n << " e: " << e << " s: " << s << " w: " << w << " avg: " << m << endl;
			grid[j*(xdim)+i] = m;
		}
	}
}

void oddStep(int *grid, int xdim, int ydim) {
    #pragma omp parallel for private(grid, xdim, ydim)
	for (int i=1; i<xdim-1; i++) {
		for (int j=1+(i+1)%2; j<ydim-1; j+=2) {
			//printf("Computing location (%d, %d) = %d\n", i, j, j*xdim+i);
			//cout << "Computing for location (" << j << "," << i << ")(" << i*(ydim)+j << ") = " << grid[i*(ydim)+j] << endl;
			int n = grid[(i-1)*(ydim)+j];
			int e = grid[i*(ydim)+j+1];
			int s = grid[(i+1)*(ydim)+j];
			int w = grid[i*(ydim)+j-1];
			int m = grid[i*(ydim)+j];
			m = (n+e+s+w+m)/5;
			//cout << "n: " << n << " e: " << e << " s: " << s << " w: " << w << " avg: " << m << endl;
			grid[j*(xdim)+i] = m;
		}
	}
}

void ocean (int **grid, int xdim, int ydim, int timesteps)
{
    /********************* the red-black algortihm (start)************************/
    /*
    In odd timesteps, calculate indeces with - and in even timesteps, calculate indeces with * 
    See the example of 6x6 matrix, A represents the corner elements. 
        A A A A A A
        A - * - * A
        A * - * - A
        A - * - * A
        A * - * - A
        A A A A A A 
    */

    // PUT YOUR CODE HERE
	for (int i=0; i<timesteps; i+=2) {
		evenStep(*grid, xdim, ydim);
		oddStep(*grid, xdim, ydim);
	}

    /////////////////////// the red-black algortihm (end) ///////////////////////////
}
