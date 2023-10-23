import sys
import matplotlib.pyplot as plt

# Extract the values from command-line arguments
classOneMale, classOneFemale, classTwoMale, classTwoFemale = map(int, sys.argv[1:])

# Create x and y values
categories = ['Males in Class 1', 'Females in Class 1', 'Males in Class 2', 'Females in Class 2']
values = [classOneMale, classOneFemale, classTwoMale, classTwoFemale]

# Create a bar graph
plt.bar(categories, values)

# Add labels and title
plt.xlabel('Type of Student')
plt.ylabel('Number of Students')
plt.title('Number of Males and Females in Each Class')

# Display the bar graph
plt.show()