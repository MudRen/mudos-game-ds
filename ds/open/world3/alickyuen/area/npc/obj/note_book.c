#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�q�l�O�ƥ�", ({ "electric note book","note","book" }) );
        set("long","�@���q�l�O�ƥ��A���ذO���F�@�ǪF��A�A�i�H����Ū���C\n");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material","iron");
        }
        setup();
}

void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
        object me,to;
        me = this_player();
        if( !arg || arg!="book" ) return 0;

        message_vision("$N���}�q�l��O���q���A�ݤF�ݸ��Y���F��C\n",me);
          tell_object(me,
CYN"\n�Y�~�Y��Y�� �P���� �Ѯ�G��    

�ڤ��ѷӱ`�h�а��ë�A��ڦV�t������ë���ɭԡA��M�@���j���A

��b�ӥi�ȤF.....���ۧڴN�ѤF����o�ͪ��Ʊ��C\n" NOR);

        return 1;
}

