inherit ITEM;
inherit F_FOOD;
void create()
{
set_name("���n", ({ "rubber" }) );
set_weight(80);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "�@�ӫܴ��q�����n,�ݰ_�Ӥ��j�n�Y�C\n");
set("unit", "��");
set("value", 10);  
set("food_remaining",2); 
set("heal_body",2);
set("heal_head",2);
set("heal_left_hand",2);
set("heal_right_hand",10);
set("heal_left_foot",10);
set("heal_right_foot",10);
}
}
