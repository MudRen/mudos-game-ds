
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�߯�",({"dead paper","paper","_DEAD_PAPER_"}) );
        set("long",@LONG
�o�O�@�i�n�S�̦b�Ϊ��߯ȡC�A�i�H�b�W���Ѽg(write)�Q�n�������F��A
�i�Ѽg�������� art, pop, exp �� money�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�i");
        }
        set("value", 1);
        setup();
}

void init()
{
    add_action("do_write","write");
}


int do_write(string arg) {
	string type, ctype;
    object me;
    me = this_player();
    
	if(arg=="art") {
		type = "art";
		ctype = "�԰����N";
	} else if(arg=="pop") {
		type = "pop";
		ctype = "�n��";
	}  else if(arg=="exp") {
		type = "exp";
		ctype = "�g���";
	} else if(arg=="money") {
		type = "money";
		ctype = "����";
	} else
		return notify_fail("�i�Ѽg�������� art, pop, exp �� money�C\n");

	message_vision("$N�b$n�W�Ѽg�W"+ctype+"���r�ˡC\n", me, this_object());	
	set("type", type);
	
	return 1;
}