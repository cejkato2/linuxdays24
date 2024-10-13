import matplotlib.pyplot as plt

# Function to load data from the text file
def load_data(filename):
    triangles = []
    times = []
    with open(filename, 'r') as file:
        for line in file:
            triangle, time = line.strip().split(',')
            triangles.append(int(triangle))
            times.append(float(time))
    return triangles, times

# Load data from both files
triangles1, times1 = load_data('reference-results.txt')
triangles2, times2 = load_data('solution-results.txt')

# Set plot style for a fancy look
plt.style.use('seaborn-v0_8-darkgrid')

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the data for both files
plt.plot(triangles1, times1, label='Python', color='blue', marker='o', linestyle='--', linewidth=2, markersize=8)
plt.plot(triangles2, times2, label='ldpymod', color='red', marker='s', linestyle='-', linewidth=2, markersize=8)

# Add titles and labels
plt.title('Comparison of Computation Time vs. Number of Triangles', fontsize=16)
plt.xlabel('Number of Triangles', fontsize=14)
plt.ylabel('Computation Time (s)', fontsize=14)

# Add a legend
plt.legend(loc='upper left', fontsize=12)

# Add grid
plt.grid(True, which='both', linestyle='--', linewidth=0.7)

# Show the plot
plt.show()
