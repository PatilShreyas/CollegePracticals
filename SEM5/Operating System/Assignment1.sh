#!bin/bash
filename="Record.txt"
tmpfile="temp.txt"

while true
do
echo "==================================" 
echo "MENU"
echo "1. Create Address Book"
echo "2. Display Address Book"
echo "3. Add Record"
echo "4. Delete Record"
echo "5. Modify Record"
echo "6. Search Record"
echo "7. Exit"
echo "==================================" 
echo "Enter your choice: "
read choice

case $choice in
	1)	# Create Record
		if [ -e $filename ]
		then 
			echo "Record Already Exists!"
		else 
			echo "Creating Address Book"
			touch $filename
			echo "$filename Created Successfully!"
		fi	
		;;
		
	2) 	# Display File
		echo "--------------------------------------"
		echo "ROLL NO        NAME     CITY"
		echo "--------------------------------------"
		cat $filename
		;;
		
	3) 	# Insert Record in File
		echo "Enter Student Roll Number: "
		read roll_no
		
		echo "Enter Student Name: "
		read name
		
		echo "Enter Student City: "
		read city
		
		echo "$roll_no        $name    $city" >> $filename
		
		echo "Record is Inserted"
		;;
		
	4)	# Delete Record 
		echo "Enter the Student Roll Number to delete: "
		read key
		
		grep -v "^$key" $filename >> $tmpfile
		
		cp $tmpfile $filename
		rm $tmpfile
		
		echo "Record is deleted"
		;;
		
	5) 	# Modify Record
		echo "Enter student roll number to find: "
		read key
		
		grep -i "^$key" $filename
		
		if [ $? -eq '0' ]
		then
			grep -v "^$key" $filename >> $tmpfile
			
			echo "Enter Student Roll Number: "
			read roll_no
			
			echo "Enter Student Name: "
			read name
			
			echo "Enter Student City: "
			read city
			
			echo "$roll_no        $name    $city" >> $tmpfile
			
			echo "Record is Modified"
			cp $tmpfile $filename
			rm $tmpfile
		else 
			echo "No Record found to modify"
		fi
		;;
		
	6) 	# Search for a Record
		echo "Enter student roll number to find: "
		read key
		
		grep -i "^$key" $filename
		
		if [ $? -eq '0' ]
		then 
			echo "Record is FOUND"
		else 
			echo "Record is not Found"
		fi
		;;
		
	7) 	exit 0 ;;
	*) 	echo "INVALID CHOICE"
		;;
esac
done
