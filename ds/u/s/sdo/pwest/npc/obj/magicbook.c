#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�]�k�ѥ�", ({"magicbook" }) );
        set("long", 
"�o�O�@���x���]�k���������y�A�A�H��½�F�@�U...�����ݤ���...\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        }
        setup(); 
}