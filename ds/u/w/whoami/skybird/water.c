#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ��t�u"NOR);

 set("long",@LONG 
�o�̴N�O�D�W�Ĭɪ��ѱ��t�u, �ǻ��o�O�@�ӵ��H���f����
, �����P�b�ڤ����ަ��u, ���H�N�u���ަ^�a��, �C�鶼��], 
�f������í�w�Ӳצܲ�¡, �q���ѱ��t�u�N�������Ī̪�������
���w���a, �L��k�h�X�ѱ����e, ���ߤU���}�n���ɤѱ�������
��, �]���Q�����u, �ѱ��𤦤@���]�q�����A���󦹳B....
LONG
    );
 set("exits",([ "south":__DIR__"bird6",
    ]));
 set("objects", ([ /* sizeof() == 1 */
       __DIR__"obj/holy_pool" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

