#include <ansi.h>
inherit NPC;
void create()
{
 set_name("行商",({"salesman"}));
 set("long",@LONG
一個正拿著毛巾擦汗的商人, 看的出來趕路的很快, 這一類的商人是沒有商品出售的.
LONG
    );
 set("attitude", "peaceful");
 set("age",30);
 set("race","人類");
 set("gender","男性");
 set("level",3);
 setup();
 add_money("coin",10000);
}
