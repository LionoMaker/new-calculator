#include <Arduino.h>

String userInput()
{ // user input from Serial monitor
  Serial.flush();
  // long t = millis();
  while (!Serial.available())
  {
  }
  String str = "";
  while (Serial.available())
  {
    char c = Serial.read();
    if (c == '\n')
      break;
    str += c;
  }
  Serial.printf("%s\n", str);
  // data = str.toInt(); // Read integer type data
  return str;
}

int sum(int n1, int n2) // sum function
{
  return (n1 + n2);
}
int minus(int n1, int n2) // minus function
{
  return (n1 - n2);
}
int multiply(int n1, int n2) // multiplication function
{
  return (n1 * n2);
}
float divide(int n1, int n2) // division function
{
  return ((float)n1 / n2);
}

void setup()
{
  Serial.begin(115200);
  String opertr; // initialization
  int num1, num2;

  Serial.printf("\n Enter First Number : ");
  num1 = userInput().toInt();
  Serial.printf("\n Enter Second Number : ");
  num2 = userInput().toInt();

  Serial.printf("\nEnter Operator or press q to exit : ");
  while ((opertr != "q") && (opertr != "Q") && (opertr != "+") && (opertr != "-") && (opertr != "/") && (opertr != "*")) // keeps asking for operator
  {
    opertr = userInput();
  }
  
  if ((opertr != "q") && (opertr != "Q"))
  {

    if (opertr == "+")
    {
      Serial.printf("\n %d + %d = %d\n", num1, num2, sum(num1, num2));
    }
    else if (opertr == "-")
    {
      Serial.printf("\n %d - %d = %d\n", num1, num2, minus(num1, num2));
    }
    else if (opertr == "*")
    {
      Serial.printf("\n %d * %d = %d\n", num1, num2, multiply(num1, num2));
    }
    else if (opertr == "/")
    {
      if (num2 != 0)
      {
        Serial.printf("\n %d / %d = %.2f\n", num1, num2, divide(num1, num2));
      }
      else
        Serial.printf("\n Zero division error\n");
    }

    else
    {
      Serial.printf("\nInvalid Input. Try Again!");
    }
  }
}
void loop()
{
}
