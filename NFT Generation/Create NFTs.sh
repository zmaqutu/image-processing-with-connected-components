#-s 11 100 -t 150 -p -w output.pgm ./data/nfts/NFTIdea.pgm

#while read parameters				#this while loop creates a file called program_arguments.txt that stores ALL items from data
#do						#...set in the format: stage_day_time (example 3_21_10)
#	IFS=' '
#	set $parameters
#	echo $1
#done < ../data/Load_Shedding_All_Areas_Schedule_and_Map.clean.final.txt > ../output/temp_output.txt

echo "Enter the maximum threshold value:" 
read set_n					# set_n is the size of the subset

count=0
cd ..						#navigete to the folder containing the make file

while [ $count -lt $set_n ]				#I will change the size of n for the different subset sizes
do						#this is a while loop that reads from the file with split data and uses each line as an argume
						#argument when running LSArray App
	read splitz				
	IFS='_'
	set $splitz
	./build/findComp -s 11 100 -t $count -p -w nft_$count.pgm ./data/nfts/NFTIdea1.pgm
	#make runMakeNFTs			#this runs my makefile with arguments
	count=`expr $count + 1`
done < output_files/temp_output.txt

echo "$set_n NFT's created..." 
