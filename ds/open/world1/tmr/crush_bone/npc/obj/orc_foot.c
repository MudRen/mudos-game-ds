inherit ITEM;

void create()
{
    set_name("�b�~�H�}�x", ({"orc's foot", "foot", "_CRUSH_BONE_FOOT_"}));
    if( !clonep() ) {
        set("long", "�@���O�O���}�x�A���~�H��.. ~.~!");
        set("unit", "��");
        set("value", 10);
        set("weight", 20);
        } else
		   set_default_object(__FILE__);
    setup();
}
