inherit ITEM;

void create()
{
    set_name("�b�~�H�Y�`", ({"orc's skull", "skull", "_CRUSH_BONE_SKULL_"}));
    if( !clonep() ) {
        set("long", "�@����O�O���Y�`�A���~�H��.. ~.~!");
        set("value", 10);
        set("unit", "��");
        set("weight", 200);
        } else
		   set_default_object(__FILE__);
    setup();
}
