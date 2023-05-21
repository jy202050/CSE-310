
//Title: Joe's Deli Breakfast 
//Desc: Develop the breakfast ordering application for Joe's Deli using javaFX
//Author: JIAYUAN YU
//Date: 05/18/2023

package application;



import javafx.application.Application;   // Entry point of the application in JavaFX
import javafx.geometry.Insets;           // Specify the amount of space or padding around the edges of a GUI component
import javafx.geometry.Pos;              // Provides various pre-defined value for alignment,(center, top, bottom, right, etc) 
import javafx.scene.Scene;               // To create and manage the content and properties of a graphical scene
import javafx.scene.control.*;           // Allows user interface controls, such as button, labels, text fields, combo boxes, list view, table views...
import javafx.scene.layout.*;            // Contains classes that represent various layout containers used for organizing and positioning UI elements within a scene
import javafx.stage.Stage;               // Displaying the user interface and handling the interaction with the operating system


public class hw1 extends Application {

  // List for Eat Section, CheckBox control (when the user select one or more options)
  private CheckBox eggSandwichCheckBox;     		// Checkbox for egg sandwich
  private CheckBox chickenSandwichCheckBox; 		// Checkbox for chicken sandwich
  private CheckBox bagelCheckBox;           		// Checkbox for bagel
  private CheckBox potatoSaladCheckBox;     		// Checkbox for potato salad
  

  // List for drink section, RadioButton (single option for the user)
  private RadioButton blackTeaRadioButton;  		// Radio button for black tea
  private RadioButton greenTeaRadioButton;  		// Radio button for green tea
  private RadioButton coffeeRadioButton;    		// Radio button for coffee
  private RadioButton orangeJuiceRadioButton;    // Radio button for orange juice
  

  // Buttons to manipulate from the order platform
  private Button orderButton;                    // Button to order the items
  private Button cancelButton;                   // Button to cancel the items
  private Button confirmButton;                  // Button to confirm the order
  

  // TextArea (to create a multi-line text input control)
  private TextArea billTextArea;                 // TextArea to display the bill
  
  
  
  
  public void start(Stage primaryStage) {
 	 primaryStage.setTitle("Joe's Deli");    // Set the title for Joe's Deli breakfast
 	
 	 // Set title(label) and name for each check box and button
 	 
 	 // List for Eat Section
 	 Label eatSectionLabel = new Label("Eat:");                       // Set eat section's label
 	 eggSandwichCheckBox = new CheckBox("Egg Sandwich");              // Set name for egg sandwich
 	 chickenSandwichCheckBox = new CheckBox("Chicken Sandwich");      // Set name for chicken sandwich
 	 bagelCheckBox = new CheckBox("Bagel");                           // Set name for bagel
 	 potatoSaladCheckBox = new CheckBox("Potato Salad");              // Set name for potato salad
 	 
 	 
 	 // List for Drink Section
 	 Label drinkSectionLabel = new Label("Drink:");                   // Set drink's section label
 	 blackTeaRadioButton = new RadioButton("Black Tea");              // Set name for black tea
 	 greenTeaRadioButton = new RadioButton("Green Tea");              // Set name for green tea
 	 coffeeRadioButton = new RadioButton("Coffee");                   // Set name for coffee
 	 orangeJuiceRadioButton = new RadioButton("Orange Juice");        // Set name for orange juice
 	 
 	 // Bill Section
 	 Label billDisplayLabel = new Label("Bill");                      // Set title for bill display area
 	 billTextArea = new TextArea();                                   // create a text area where the bill will displayed
 	 billTextArea.setEditable(false);                                 // set editable of the text area to false (to prevent users edit the text in the text area)
 	 
 	 // List to manipulate order (Order, Cancel, Confirm)
 	 orderButton = new Button("Order");                               // Set name for order button
 	 cancelButton = new Button("Cancel");                             // Set name for cancel button
 	 confirmButton = new Button("Confirm");                           // Set name for confirm button
 	 
 	 
 	 
 	 
 	 // Positioning the check-boxes and buttons
 	 
 	 // Positioning for Eat Section
 	 // Set each eat box spacing to 15 pixels and set all nodes to stacked vertically within the VBox
 	 VBox setVBoxForEatSection = new VBox(15, eatSectionLabel, eggSandwichCheckBox, chickenSandwichCheckBox, bagelCheckBox, potatoSaladCheckBox); 
 	 setVBoxForEatSection.setPadding(new Insets(15));                // Sets the padding around the VBox to 15 pixels on all sides.
 	 setVBoxForEatSection.setAlignment(Pos.CENTER_LEFT);             // Set all nodes(Eat) centered horizontally and aligned to the left vertically within the VBox
 	 
 	 
 	 // Positioning for Drink Section
 	 // Set each drink box spacing to 15 pixels and set all nodes to stacked vertically within the VBox
 	 VBox setVBoxForDrinkSection = new VBox(15, drinkSectionLabel, blackTeaRadioButton, greenTeaRadioButton, coffeeRadioButton, orangeJuiceRadioButton);
 	 setVBoxForDrinkSection.setPadding(new Insets(15));              // Sets the padding around the VBox to 15 pixels on all sides.
 	 setVBoxForDrinkSection.setAlignment(Pos.CENTER_LEFT);           // Set all nodes(Drink) centered horizontally and aligned to the left vertically within the VBox
 	 
 	  
 	 // Positioning for bill display section
 	 // Set each eat box spacing to 15 pixels and set all nodes to stacked vertically within the VBox
 	 VBox setBillDisplayArea = new VBox(15, billDisplayLabel, billTextArea);
 	 setBillDisplayArea.setPadding(new Insets(15));                  // Sets the padding around the VBox to 15 pixels on all sides.
 	 setBillDisplayArea.setAlignment(Pos.CENTER_LEFT);               // Set all nodes(bill) centered horizontally and aligned to the left vertically within the VBox
 	 
 	 
 	 // Positioning for manipulate buttons Section
 	// Set each eat box spacing to 50 pixels and set all nodes to stacked horizontally within the VBox
 	 HBox setHBoxForManipulateOrder = new HBox(50, orderButton, cancelButton, confirmButton);
 	 setHBoxForManipulateOrder.setPadding(new Insets(20));           // Sets the padding around the VBox to 20 pixels on all sides.
 	 setHBoxForManipulateOrder.setAlignment(Pos.CENTER);             // Set all nodes(Manipulate buttons) centered 
 	 
 	 
 	 
 	 // Set Toggle function for drink order (Only one type of drink can be selected)
 	 ToggleGroup drinkListToggle = new ToggleGroup();               // Use toggle group function to enforce that only one drink can be selected at once
 	 
 	 // Assign function to each drink item to ensures that selecting one radio button will deselect the others
 	 blackTeaRadioButton.setToggleGroup(drinkListToggle);           
 	 greenTeaRadioButton.setToggleGroup(drinkListToggle);
 	 coffeeRadioButton.setToggleGroup(drinkListToggle);
 	 orangeJuiceRadioButton.setToggleGroup(drinkListToggle);
 	 
 	 
 	 
 	 // Set the general position of each section (Eat section, Drink section, Bill display area, manipulate buttons section)
 	 BorderPane setSectionBorderPane = new BorderPane();            // Create BorderPane named setSectionBorderPane to organize the sections of the GUI
 	 setSectionBorderPane.setLeft(setVBoxForEatSection);            // Set setVBoxForEatSection as the content in the left area of the border pane
 	 setSectionBorderPane.setCenter(setVBoxForDrinkSection);        // Set setVBoxForDrinkSection as the content in the center area of the border pane
 	 setSectionBorderPane.setRight(setBillDisplayArea);             // Set setBillDispayArea as the content in the right area of the border pane
 	 setSectionBorderPane.setBottom(setHBoxForManipulateOrder);     // Set setHBoxForManipulateOrder as the content in the bottom area of the border pane
 
 	 
 	 // Create scene and sets it on a Stage to display the GUI
 	 // Creates a new Scene object name menuScene with specified setSectionBorderPane
 	 // The width of the scene is set to 300 pixels and the height is set to 200 pixels
 	 Scene menuScene = new Scene(setSectionBorderPane, 800, 300);   
 	 primaryStage.setScene(menuScene);                              // Sets the created scene as the menuScene to be displayed on the primaryStage stage
 	 primaryStage.show();                                           // Display the primary stage along with the configured scene
 	 
 	 
 	 // Button action (point to each method)
 	 orderButton.setOnAction(event->placeCustomerOrder());          // sets placecustomerOrder method as the action to be performed when the orderButton is clicked
 	 cancelButton.setOnAction(event->cancelCustomerOrder());        // Sets cancelCustomerOrder method as the action to be performed when the orderButton is clicked
 	 confirmButton.setOnAction(event->confirmCustomerOrder());      // Sets confirmCustomerOrder method as the action to be performed when the orderButton is clicked
 	  	    	     	 
  }
  
  // Method to place customer's order
  private void placeCustomerOrder() {
       double preTaxTotalCost = 0.0;                                 // Initialized the preTaxTotalCost to 0
       StringBuilder textInfoAppend = new StringBuilder();           // Create object named textInfoAppend to store the bill infomation as string
       textInfoAppend.append("------Item Info------\n");
       
       // Add 7.99 to the preTaxTotalCost when eggSandwichCheckBox is clicked
       if (eggSandwichCheckBox.isSelected()) {
     	  preTaxTotalCost += 7.99;   
     	  textInfoAppend.append("Egg Sandwich: $7.99 each\n");      // Show text info when eggSandwichCheckBox is clicked    	  
       }
       
       // Add 9.99 to the preTaxTotalCost when chickenSandwichCheckBox is clicked
       if (chickenSandwichCheckBox.isSelected()) {
     	  preTaxTotalCost += 9.99;
     	  textInfoAppend.append("Chicken Sandwich: $9.99 each\n");  // Show text info when chickenSandwichCheckBox is clicked
       }
       
       // Add 2.50 to the preTaxTotalCost when bagelCheckBox is clicked
       if (bagelCheckBox.isSelected()) {
     	  preTaxTotalCost += 2.50;
     	  textInfoAppend.append("Bagel: $2.50 each\n");             // Show text info when bagelCheckBox is clicked
       }
       
       // Add 4.49 to the preTaxTotalCost when potatoSaladCheckBox is clicked
       if (potatoSaladCheckBox.isSelected()) {
     	  preTaxTotalCost += 4.49;
     	  textInfoAppend.append("Potato Salad: $4.49 each \n");     // Show text info when potatoSaladCheckBox is clicked
       }
       
       // Add 1.25 to the preTaxTotalCost when blackTeaRadioButton is clicked
       if (blackTeaRadioButton.isSelected()) {
     	  preTaxTotalCost += 1.25;                                  
     	  textInfoAppend.append("Black Tea: $1.25 each\n");         // Show text info when blackTeaRadioButton is clicked
       }
 	 
       // Add 0.99 to the preTaxTotalCost when blackTeaRadioButton is clicked
       if (greenTeaRadioButton.isSelected()) {
     	  preTaxTotalCost += 0.99;                                  
     	  textInfoAppend.append("Green Tea: $0.99 each\n");         // Show text info when greenTeaRadioButton is clicked
       }          
       
       // Add 1.99 to the preTaxTotalCost when coffeeRadioButton is clicked
       if (coffeeRadioButton.isSelected()) {
     	  preTaxTotalCost += 1.99;
     	  textInfoAppend.append("Coffee: $1.99 each\n");            // Show text info when coffeeRadioButton is clicked
       }
       
       // Add 2.25 to the preTaxTotalCost when orangeJuiceRadioButton is clicked
       if (orangeJuiceRadioButton.isSelected()) {
     	  preTaxTotalCost += 2.25;  
     	  textInfoAppend.append("Orange Juice: $2.25 each\n");      // Show text info when orangeJuiceRadioButton is clicked
       }
       
       double taxCost = (preTaxTotalCost * 0.07);                    // Calculate the tax amount(7%)
       double totalCost = (preTaxTotalCost + taxCost);               // Calculate the total cost after tax
       
       // Append the separate line for subtotal, tax amount and final total cost, and format the decimal value to two places
       textInfoAppend.append("------Bill Info------\n");
       textInfoAppend.append("Subtotal Cost: ").append(String.format("%.2f\n", preTaxTotalCost));
       textInfoAppend.append("Tax(7%): ").append(String.format("%.2f\n", taxCost));
       textInfoAppend.append("Total Cost: ").append(String.format("%.2f\n", totalCost));
       
       
       // Sets the generated bill text info to the billTextArea for display
       billTextArea.setText(textInfoAppend.toString());
                                                            
  }
  
  // Method to cancel customer's order
  private void cancelCustomerOrder() {
 	 eggSandwichCheckBox.setSelected(false);                       // Set the eggSandwichCheckBox to be deselected (unchecked)
 	 chickenSandwichCheckBox.setSelected(false);                   // Set the chickenSandwichCheckBox to be deselected (unchecked)
 	 bagelCheckBox.setSelected(false);                             // Set the bagelCheckBox to be deselected (unchecked)
 	 potatoSaladCheckBox.setSelected(false);                       // Set the potatoSaladCheckBox to be deselected (unchecked)
 	 blackTeaRadioButton.setSelected(false);                       // Set the blackTeaRadioButton to be deselected (unchecked)
 	 greenTeaRadioButton.setSelected(false);                       // Set the greenTeaRadioButton to be deselected (unchecked)
 	 coffeeRadioButton.setSelected(false);                         // Set the coffeeRadioButton to be deselected (unchecked)
 	 orangeJuiceRadioButton.setSelected(false);                    // Set orangeJuiceRadioButton to be deselected (unchecked)
 	 billTextArea.setText(" ");                                    // Clears the content of the billTextArea
  }  
  
  // Method to confirm customer's order
  private void confirmCustomerOrder() {
 	 
 	 Alert orderConfirm = new Alert(Alert.AlertType.INFORMATION);  // Create an instance of Alert with the INFOMATION type, which display an information icon in the dialog
 	 orderConfirm.setTitle("Order Confirm");                       // Set the alert title to order confirm
 	 orderConfirm.setHeaderText(null);                             // Clear any header displayed in the dialog
 	 orderConfirm.setContentText("Order Confirm! Please wait in the pick-up area.");
 	 orderConfirm.showAndWait();                                   // Display the confirmation alert and 
 	                                                               // waits for the user to close it before continuing the execution of the code
  }
  
  
  
  
  
  
	 public static void main(String[] args) {
	     launch(args);                                                 // launch javaFX application and start the javaFX runtime system
	}
	
}
