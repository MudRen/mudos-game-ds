#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���G�p�E");
        set("long", @LONG
�@�ӥH�X�ڤ��Y�γ¥��f�_�Ӫ�²���פl�A���U�\�F�@
�c�c�����G�򦨤F�@��A���n�h�áA�o�O�@�ӹD�D�a�a����
�G�E�A�o�Ǥ��G�j�h�O���q���~�A�����и̱Ħ��U�Ӫ��s
�A�f�~�C
LONG
        );
        set("exits", ([ 
                        "west" : __DIR__"wn1av1",
            ]));
           set("item_desc",([
"�ůȽc" : "
�@�Ӫſ������Ƚc�A�̭����X������...\n",
                 ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
int room_effect(object me)
{

         switch(random(6))
        {
         case 0:
         write("�@���G�ǭ���L�ӡ�A����L�h��A�̫ᰱ�b�A����l�W...\n");
         return 1;
         default:       return 1;
        }
}


