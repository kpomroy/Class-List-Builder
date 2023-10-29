import sys
import matplotlib.pyplot as plt

# Extract the values from command-line arguments
classOneMale, classOneFemale, classTwoMale, classTwoFemale = map(int, sys.argv[1:])

# Create x and y values
categories = ['Males in Class 1  ', 'Females in Class 1  ', 'Males in Class 2  ', 'Females in Class 2  ']
values = [classOneMale, classOneFemale, classTwoMale, classTwoFemale]

# Set each bar to be a color
colors = ['b', 'r', 'b', 'r']

# Create a bar graph with different colors for gender
plt.bar(categories, values, color=colors)

# Add labels and title
plt.xlabel('Gender of Student')
plt.ylabel('Number of Students')
plt.title('Number of Males and Females in Each Class')

# Save plot as png to import from html code
plt.savefig('M3OEP_plot.png')

# Display the bar graph
plt.show()