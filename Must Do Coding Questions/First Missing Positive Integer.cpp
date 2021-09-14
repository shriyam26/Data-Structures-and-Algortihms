int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int lastFilledIndex = size;
        
        int idx = 0;
        while(idx < size){
            
            // when index reached up to last filled index then should return that element ( idx + 1)
            // because idx-1 is the last index up to where we have ensured that all positive element is present in array.
            // We also know that after this point all value is greter of size or less than 0 ( all unused element)
            if(idx == lastFilledIndex) return lastFilledIndex+1;
            
            // check the condition if next positive value is not matched 
            if(nums[idx] != idx+1){
                if(nums[idx] <= 0 || nums[idx] > size) { // check if value is outside the range [1, 2, 3........size] 
                    
                    // swap with the last nonfilled index which is lastfilledIndex-1
                    swap(nums[idx], nums[--lastFilledIndex]);
                    
                }else{ // now if next positive value is not matched 
                    
                    // if value at index ( where index is the same as nums[idx]-1 ) is equal to value 
                    if(nums[nums[idx]-1] == nums[idx]){
                        
                        // then throw this value at the end of array
                        // This case will arise in array when it's contain duplicate values in the range
                        // Example : [1,1]
                        //         idx = 0;
                        //          1) at first it will pass value and no operation perfomed simply increase the index (idx + 1 == 1)
                        //          2) now value is not to next positive value (idx + 1 != 1) OR (2 != 1) so have to throw this value 
                        //             otherwise it will result in the endless loop. 
                        swap(nums[idx], nums[--lastFilledIndex]);
                        
                    }else{ // if value at index ( where index is the same as nums[idx]-1 ) is not the equal to value
                        
                        // place the value at it's right location in the array using swap
                        swap(nums[idx], nums[nums[idx]-1]);
                    }
                }
                
                continue;
            }
			
			// next positive interger is equal to value ( mean: it is persent in array ) 
			// then simply increse the initial pointer
            idx++;
        }
        
        // return the next Positive integer which is not persent in array
        return idx+1;
    }
