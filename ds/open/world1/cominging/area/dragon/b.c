// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
        set("objects", ([ __DIR__"item/weapon_shelf" : 1,
                          __DIR__"item/equip_shelf" : 1,
                          __DIR__"item/item_shelf" : 1, ]));
        set("light",1);
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)

	setup();
}
