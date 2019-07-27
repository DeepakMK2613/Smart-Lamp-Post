# Smart-Lamp-Post Platform Development
This my Final year M-Tech (Embedded Systems) project in EEE dept. PES University.

The project is an attempt to work on solutions around street lights to reduce the electric energy consumption and to make use of technologies to collect relevant data towards managing the resources. It is very obvious to go for renewable solution and depend on solar energy that is available in abundance. Thus the project is to advance the existing street lamps to include more sensors and controls and make it a smart lamp post. The project work is an experimental step towards the deployment in PES University. The solution comprised of solar based charging using solar controller, LED light output for street lighting and communication network currently based on GSM. 

The following features are incorporated on smart lamp post:

(i)	System running solely on solar energy

(ii)	Automatic light control (PWM control) for day and night.

(iii)	Real time data of temperature, humidity and various other sensors which are available can be uploaded to the server that can help data analytics and any further actions based on it.

(iv)	Humidity and temperature is displayed on Red LED display.

The solution is incorporated using Arduino as microcontroller, SIM800C as GSM module to send the data to ThingSpeak server. The data from various sensors are uploaded to server once in every 15 minutes. The theoretical postulation of power consumption for a day was calculated and compared with the actual measurements in the system. The uploaded data was analysed for the charging and discharging of battery. In this project we have tested with two batteries by initially charging it. Battery-1 discharged 535Wh while running the entire setup whole night and Battery-2 discharged 441Wh whole night.  The location where solar panels where placed did not get enough light during first half of the day and hence was not good enough to self-sustain the system. It is to be experimented at a different location. However the experimental setup is a lead towards the deployment in the campus.

The complete details of my project is in "Smart Lamp Post Platform Development-Report.pdf"
