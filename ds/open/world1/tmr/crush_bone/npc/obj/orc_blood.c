inherit ITEM;

void create()
{
    set_name("�b�~�H��G", ({"orc's blood", "blood", "_CRUSH_BONE_BLOOD_"}));
    if( !clonep() ) {
        set("long", "�@�~�b�~�H������G�A���_���X�c��A���طQ�R���Pı�C");
        set("unit", "��");
        set("value", 100);
        set("unit", "�~");
        set("weight", 20);
        } else
		   set_default_object(__FILE__);
    setup();
}

