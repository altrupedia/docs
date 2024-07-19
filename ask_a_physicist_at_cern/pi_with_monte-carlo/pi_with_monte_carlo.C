#include <iostream>
#include <random>

int main(int argc, char* argv[])
{
    size_t N = 1000;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0., 1.);

    size_t n_inside_circle = 0;

    for (size_t i=0; i<N; ++i)
    {
        float x = dist(mt);
        float y = dist(mt);  
        float r = sqrt(x*x + y*y);      
        printf("iteration: %lu, x = %f\ty = %f\tr = %f\n", i, x, y, r);

        if (r < 1.) 
        {
            ++n_inside_circle;
        } 

        // calculate estimate of pi
        float pi_est = 4 * n_inside_circle / static_cast<float>(i+1);
        printf("our estimate of pi after %lu iterations: pi_est = %f\n\n", i+1, pi_est);
    }
}