inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�һĶ���", ({ "hard drink","drink" }) );
        set_weight(50);
        set("long", "�o�O�@���ΨӸɥR��O�����ơA��(drink)�F�i�H�Ѵ��ɥR��O(HP)�C\n");
        set("unit", "�~");
        set("drink_msg","$N���_�@�~$n�A�B�P�B�P�a�ܤF�@�j�f�C\n");
        set("finish_drink_msg","$N�N�l�U��$n�ܥ��F�C\n");
        set("value", 50);
        set("heal_hp",50);
        set("water_remaining", 3);
        setup();
}