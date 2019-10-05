/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication6;

/**
 *
 * @author eda
 */
public class myexception extends Exception 
{
    public String msj;
    public myexception(String message)
    {
        this.msj = msj;
    }
    public String getMsj()
    {
        return msj;
    }   
}


