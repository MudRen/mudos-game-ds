inherit ITEM;
inherit F_FOOD;
void create()
{
set_name("超級膠囊", ({ "rubber" }) );
set_weight(80);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "一個很普通的膠囊,看起來不大好吃。\n");
set("unit", "個");
set("value", 10);  
set("food_remaining",2); 
set("heal_hp",1000);  
set("heal_mp",1000);     
set("heal_ap",1000);  
set("heal_body",50);
}
}
