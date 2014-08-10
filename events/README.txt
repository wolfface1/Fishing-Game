

                >>>>>>>>>>>>>>>>>>>>>Generate your own events!<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  To create your own event is pretty simple:
    -All the events are loaded from xml file from this directory
    -Each event is designated its own ID, because of this it is possible to override an existing event with your own by assigning it the same ID. To see wich Ids are being 
      used can look through the other xmls in the directory. In the future I hope to write a simple tool that displays all events and there effects in one list.
    -Each event should consist of one element with an attribute that contains the ID and text wich holds the event information.
  
  Event information:
    -Event information is the information that the program uses to decide what to do when this particular event occours.
    -When writing your own event information you must comply to the rules or else event generation will fail.
  
                          
                          
                          
                             ------Writing your own events------

    Basic syntax:
      [VAR][ACTION][TEXT]
       
       
      -VAR = What you want to change a list of possible variables can be found below in "------Variables------"
      -ACTION = What you want to do with that variable this differs from variable to variable. A list of possiblities can be found in "------Variables------".
      -TEXT = the text that is displayed to the user when the event occours (shows up in logging);
       
      
      E.g. <Event id="2">[H][SET=-100][The great god of honour has decided you stink!]</User>
      
                             
                             
                             
                                  ------Variables------
    
    Here is a list of variables that can be currently interated with. The actual variable is contained in the quotation marks e.g. "H" would be supplied as [H][SET=50]
      
      -"H" = changes the hounour Max = 100, Min = -100;
         ACTIONS:
           -"SET=INT" --> sets the honour to INT. 
           -"ADD=INT" --> Add specific amount honour (if INT is minus then it subtracts that amount)
      
      -"AF" = Adds A fish to specific cell if possible otherwise itdoes nothing.
         ACTIONS:
           -"X=INT:Y=INT" --> sets Coordinates to INT, if out of range maximum cell is chosen
           
      -"RF" = Removes a Fish from a Cell
        ACTIONS:
          -"NUM=INT"  --> The number of fish removed is equal to int. If negative then the number is set to positive .If 0 the number is set to one
       
       
    Extra Notes:
      -To get the program to use a random number in place of int use the wildcard character (*).
      
      
                                  
    **************************Note Chains have not been implemented yet.
                                  
                                  ------Event Chains------
    
    Generating event chains is a good way of making psuedo-custom events.
      To create an event chain all you have to do is to encapsulate a list of events in a Xml element titeled "Chain". If the events already exist you can use the special element
      that countains the item Id but a wildcard in the event information section.
      
      However the first child element must be a text node that contains text that is displayed to the user on the occourance of this event. Call the child "text".
      
      E.g. 
        <Chain>
          <Text>Two gods got a bit upset. Guess who?</Text>
          <Event id="2">[H][SET=-100][The great god of honour has decided you stink!]</User>
          <Event id="4">*</User>
        </Chain>