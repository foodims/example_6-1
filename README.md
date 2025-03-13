# Final Project: Automated Toaster for Fire Safety
## Sami Foodim and Kye Norcross

### Project Overview:
Toaster fires cause over 700 deaths annually worldwide, with nearly 3,000 U.S. incidents from 2007-2011 resulting in $27 million in damages. 
Unattended cooking due to distractions, busy schedules, or hearing impairments is the leading cause. We propose an automated toaster system with built-in fire safety features. 
It will monitor for smoke and abnormal temperature rises, alerting users before a fire starts. Safety checks will prevent operation without food. 
Users will indicate food placement (slider switch), turn the toaster on (slider switch), and select toast level (potentiometer), displayed on an LCD. 
While toasting, the system will detect smoke (MQ-2 sensor) and overheating (LM35 sensor) and alert users loudly. 


### System Behavior:
Our system can be broken into two different categories of functionality, cooking and alarm. The cooking functionality behaves by having the user indicate whether food is in the toaster
by flipping a slider switch. Additionally, the user will indicate whether the toaster is turned on or off with a slider switch. The user will then use a potentiometer to select their 
desired darkness between "light", "medium", and "dark". If the user properly indicates that the toaster is being used properly (food in and on) the green LED turns on indicating that 
everything is working as intended. If the user does not use the toaster properly the red LED turns on and the buzzer beeps indicating to the user that they need to either turn it on or 
put their food in. The alarm system will activate if temperature rises above the threshold level or if gas is detected. This will loudly turn on the buzzer and turn the red LED on. 
Finally, the LCD displays the selected darkness level, time remaining, and if any incidents are occuring (gas detected or temp too high).  

### Summary of Testing Results:


### Modular Design
