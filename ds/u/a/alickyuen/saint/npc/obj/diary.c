#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�q�l�O�ƥ�", ({ "electric note book","note","book" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�@���q�l�O�ƥ��A���ذO���F�@�ǪF��A�A�i�H����Ū���C\n");
                set("value", 0);

        }
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        object me,to;
        me = this_player();
        if( !arg ) return 0;
if(arg != "�q�l�O�ƥ�" && arg !="electric note book" && arg !="note" && arg !="book" ) return 0;
if( me->query_temp("readdi") )
{
    return 0;
}
        message_vision("$N���}�q�l��O���q���A�ݤF�ݻq�Y���F��C\n",me);
tell_object(me, HIW"�Y�~�Y��Y��A�P����A��    \n\n"NOR 
HIW"�ڤ��ѷӱ`�h�а��ë�A��ڦV�t������ë���ɭԡA��M�@���j���A\n"NOR
HIW"��b�ӥi�ȤF...���ۧڴN�ѤF����o�ͪ��Ʊ��C\n\n\n\n\n"NOR
YEL"�A�Q�F�@�Q�A�Ǥ��o��������鴣�ߦQ�x�A�s���а��ئ��@�Ǥ���H\n"NOR);
        me->set_temp("readdi",1);
        return 1;

}