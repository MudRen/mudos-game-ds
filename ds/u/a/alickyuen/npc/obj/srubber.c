inherit ITEM;
inherit F_FOOD;
void create()
{
set_name("�W�Ž��n", ({ "rubber" }) );
set_weight(80);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "�@�ӫܴ��q�����n,�ݰ_�Ӥ��j�n�Y�C\n");
set("unit", "��");
set("value", 10);  
set("food_remaining",2); 
set("heal_hp",1000);  
set("heal_mp",1000);     
set("heal_ap",1000);  
set("heal_body",50);
}
}
