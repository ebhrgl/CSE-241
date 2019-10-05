/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Eda BAHRIOGLU 131044055 HW8
 */
package javafxapplication6;
 
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import java.util.stream.IntStream;
import javafx.scene.paint.Color;
import javafx.scene.shape.Shape;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Circle;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import javafx.geometry.Point2D;
import java.util.stream.Collectors;
import javafx.animation.TranslateTransition;
import javafx.util.Duration;
import javax.swing.JOptionPane; // program uses JOptionPane

//ConnectFour class
public class ConnectFour extends Application  {

    private String firstNumber = JOptionPane.showInputDialog("Enter BoardSize");
    private int number1 = Integer.parseInt( firstNumber );
    private Cell obj = new Cell(number1);
    private String user  = JOptionPane.showInputDialog("1 -> User-user : P \n2 -> user-computer : C"); 
    private Cell obj1 = new Cell(user);
    private Point2D cross;
    private List<Point2D>gameboard;
    private List<Rectangle> arrList;
    private boolean user1Move = true;
    private Cell[][] gameCell = new Cell[obj.getBoardSize()][obj.getBoardSize()];
    private Pane ballMove = new Pane();
    private static int Table_Size; 
       
    //private inner Cell class
    private static class Cell extends Circle
    {
        private int boardSize;
        private String player;
        private boolean red;

        //Cell class constructors
        public Cell()
        {
           setBoardSize(4);
        }
          
        public Cell(boolean redValue)
        {
            super(Table_Size/2, redValue ? Color.RED : Color.BLUE);
            red = redValue;
            setPlayer(".");
        }
        
        public Cell(String playerValue)
        {
            setPlayer(playerValue);
        }

     
       public Cell(int boardSizeValue)
       {
           setBoardSize(boardSizeValue);  
       }

       //cell class setters
       public  void setBoardSize( int boardSizeValue)
       {
            if(boardSizeValue<4)
            {
                System.err.println( "invalid command"); 
                String firstNumber = JOptionPane.showInputDialog("Enter BoardSize");
                int number1 = Integer.parseInt( firstNumber );
                Cell x = new Cell(number1);
       
            }
            boardSize = boardSizeValue;
       }
       public void setPlayer(String newPlayer)
       {
           player = newPlayer;
       }
       //Cell class getters
       public int getBoardSize()
       { 
           return boardSize;
       }
       
       public String getPlayer()
       {
           return player;
       }

    }
    
    //Connectfour constructor
    public ConnectFour()
    {
        Table_Size = 50;
    }
    
    //Boardun olustugu kısımdır.
    public Shape startingBoard()
    { 
        Shape shape = new Rectangle((obj.getBoardSize()+1) * Table_Size, (obj.getBoardSize()+1)* Table_Size);
        
        for(int j=0; j<obj.getBoardSize(); j++)
        {
            for(int i=0; i<obj.getBoardSize(); i++)
            {
                Circle circle =new Circle(obj.getBoardSize()*3);
                circle.setCenterX(obj.getBoardSize()*3);
                circle.setCenterY(obj.getBoardSize()*3);
                circle.setTranslateX(i * (Table_Size )+ Table_Size/2);
                circle.setTranslateY(j * (Table_Size )+ Table_Size/2);
              shape = Shape.subtract(shape,circle);
            }
        }
        shape.setFill(Color.CHOCOLATE);
        return shape;
    }
   
    //Oyunun oynanmaya baslandıgı kisimdir.
    public List<Rectangle>play()
    {
        arrList = new ArrayList<>();

        for (int i=0; i<obj.getBoardSize(); i++)
        { 
            int col;
            Rectangle rect = new Rectangle(Table_Size,(obj.getBoardSize())* Table_Size);
            rect.setTranslateX(i * (Table_Size));
            rect.setFill(Color.TRANSPARENT);
            col = i;

            rect.setOnMouseClicked(e->winBall(new Cell(user1Move),col));
            arrList.add(rect);

        }
        return arrList;
    }
    
    //Kazanani veren fonksiyondur.
    private void winBall(Cell arr, int col)
    {
        int row= obj.getBoardSize()-1;
        
         while(row >= 0)
         {
          if(!getBall(col, row).isPresent())
              break;
              row--;
         }
  
         gameCell[col][row] = arr;
         ballMove.getChildren().add(arr);
         arr.setTranslateX((col * Table_Size) + Table_Size);
         final int newrow = row;
         
         TranslateTransition animation = new  TranslateTransition(Duration.seconds(0.6),arr);
         animation.setToY((row * Table_Size) + Table_Size);
        
         if(gameEnd(col, newrow ))
         {    
            System.out.println("win: "+(user1Move ? "user1" : "user2"));
         } 
           user1Move = !user1Move;
           animation.play();   
    }
    
    //Oyunun sonlandıgı sonucu veren kisimdir.
    public boolean gameEnd(int col, int row)
    { 
       if( legalCheck(downMove(col, row)))
       {
           return true;
       }
       else if( legalCheck(rightMove(col,row))) 
       {
           return true;
       }
       else if(legalCheck(crossLeftMove(col, row)) )
       {
           return true;
       }
       else if(legalCheck(crossRightMove(col, row)))
       {
           return true;
       }
       else
           return false;
    }
    
    //Dusey hareketin yapildigi kisimdir.
    private List<Point2D> downMove(int col, int row)
    {
        gameboard  = IntStream.rangeClosed(row -3, row +3)
        .mapToObj(r-> new Point2D(col,r)).collect(Collectors.toList());
        return gameboard;
    }
    
    //Yatay hareketin yapildigi kisimdir.
    private List<Point2D> rightMove(int col, int row)
    {
        gameboard = IntStream.rangeClosed(col -3, col + 3)
        .mapToObj(c-> new Point2D(c,row)).collect(Collectors.toList());
        return gameboard; 
    }
    
    //sol capraz hareketin yapildigi kisimdir.
    private List<Point2D> crossLeftMove(int col, int row)
    {    
        cross= new Point2D(col-3, row-3);
        gameboard = IntStream.rangeClosed(0,6)
        .mapToObj(l->cross.add(l,l)).collect(Collectors.toList());     
        return gameboard;
    }
    
    //Sag capra hareketin yapildigi kisimdir.
    private List<Point2D> crossRightMove(int col, int row)
    {   cross = new Point2D(col-3, row+3);
        gameboard = IntStream.rangeClosed(0,6)
        .mapToObj(r->cross.add(r,-r)).collect(Collectors.toList());     
        return gameboard;
    }
    
    //kontrollerin yapıidigi fonksiyondur.
    private boolean legalCheck(List<Point2D> points)
    {
        int count=0;
        for(Point2D p : points)
        {
            int col = (int) p.getX();
            int row = (int) p.getY();
            Cell arr = getBall(col, row).orElse(new Cell(!user1Move));
            if (arr.red == user1Move)
            { 
                count++;
                if(count == 4)
                {  
                    return true;
                } 
            }
        }
        return false;
    }
    
    //Arrayin dolduruldugu fonksiyondur.
    private Optional<Cell> getBall(int col, int row)
    {
        if(col<0||col>=obj.getBoardSize() || row<0 || row>= obj.getBoardSize())
            return Optional.empty();
        else
            return Optional.ofNullable(gameCell[col][row]);
    }
 
     @Override
     //baslangic durumdur.Tğm fonklar burada cagrilir.
     public void start(Stage primaryStage)throws myexception
     {
        
        Pane begin=new Pane();
      
        begin.getChildren().add(ballMove);
        Shape gameCellshape = startingBoard();
        begin.getChildren().add(gameCellshape);
        if(obj1.getPlayer() != "C" || obj1.getPlayer() != "c")
        {
            begin.getChildren().addAll(play());
        }
        primaryStage.setScene(new Scene(begin));
        primaryStage.show();
         
     }

     //main fonksiyonudur.
     public static void main(String[] args) 
     {
        
          try 
        {
            launch(args);
        } 
         
        catch (Exception e) 
        {
            System.out.println("Exception caught: " + e);
        }  
     }
    
}
