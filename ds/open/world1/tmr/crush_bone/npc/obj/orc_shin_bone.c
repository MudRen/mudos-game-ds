inherit ITEM;

void create()
{
    set_name("�b�~�H�H��", ({"orc's shin bone", "bone", "_CRUSH_BONE_SHINBONE_"}));
    if( !clonep() ) {
        set("long", "�@���O�O���H���A���~�H��.. ~.~!");
        set("value", 10);
        set("unit", "��");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
