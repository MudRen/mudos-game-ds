inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��i�w", ({ "Vitamin pin","pin" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�K�w�A�ݨӤ��j�n�Y.......\n");
                set("unit", "��");
                set("value", 10);  
                set("food_remaining",8);
                set("heal_hp",50+random(10));  
  set("eat_msg","$N��w�����F�F���X��,�M��]�U...�n�ä�...\n");
        set("finish_eat_msg","$N�N�w���l�U���F�F�Y���F�C\n");
        }
}