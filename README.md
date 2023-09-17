# granian (newtonian gravitation)

granian is a C++ application utilizing Newton's equation of motion to simulate gravitational forces on celestial bodies in two-dimensional space

<b> /!\ you need to setup SFML /!\\</b>

for example this is a planet 10 times smaller than the earth orbiting it :
```cpp
object *planet = new object(vector(20000, 2), Vector2(0, screenY / 2), 70000000000000000);
planet->getShape()->setFillColor(sf::Color::Red);
listOfObjects.push_back(apple);


object *earth = new object(vector(0, 0), Vector2(screenX / 2, screenY / 2), 5970000000000000000);
earth->getShape()->setFillColor(sf::Color::Blue);
listOfObjects.push_back(earth);
```
<img src="https://cdn.discordapp.com/attachments/939310069789630524/1153101142100815933/granian_QSMoW5AEDy.gif" alt="example">


with this code with can simulate the fall of an apple on earth
```cpp
object *apple = new object(vector(0, 0), Vector2(screenX / 2, screenY / 2), 0.00000102);
apple->getShape()->setFillColor(sf::Color::Red);
listOfObjects.push_back(apple);


object *earth = new object(vector(0, 0), Vector2(screenX / 2, 6371), 5970000000000000000);
earth->getShape()->setFillColor(sf::Color::Blue);
listOfObjects.push_back(earth);
```
<img src="https://cdn.discordapp.com/attachments/1009891289770242120/1153099331260383303/granian_nrHYXnYZrI.gif" alt="Image">
