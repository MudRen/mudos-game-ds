/*      File : /open/world1/alickyuen/match/obj/doll.c        
        Author: Alickyuen@DS 
        Last Modify: 2002-5-25
        Special Thanks To: Acme@DS        */

#include <ansi2.h>

#define START_ROOM "/open/world1/alickyuen/match/exit.c"

inherit ITEM;


void create()
{
        set_name("��������"HIW"[���ɱM��]"NOR, ({ "match doll", "doll", "undead_item" }) );
        set_weight(100);
        set("value", 0);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
        set("unit", "��");
        set("long", @long
�@�Ӹ޲����v�����A�����⪺�Ȥl�W���۳\�h�զ⪺�p���I�A
�R�����������F��...�A���G�ݨ�o�b�w�����I�H
���O�o�����ɪ��ʹ�H�A��A���A���|�a�A�h��w�����a��C
long);
        set("undead_msg", " ");
        set("wimpy_msg", " ");
        set("start_place", START_ROOM);

        setup();
}

