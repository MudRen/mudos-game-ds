#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�X�Y");
        set("long",@LONG
�������X�Y�즹�����A�a���Ш��������A�@��L�ڪ��j���A����[��
���n���A�����ɵo�X���V���n�A�X�ӪF��Ӫ��ȤH���b�o�̡A�յۦb
�������W��M�ۤv���G�m�A�b�o���ꪺ�g�a�W�C
LONG 
);
        set("exits",([
            "east":__DIR__"port_05",
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();

}

int room_effect(object me)
{
        switch(random(14))
        {         case 6:        message_vision("������㻷���W�ǨӤF�C�I�������n�C\n",me);
                        return 1;
         case 0:        message_vision("�a���Ш��������I�I���j�ۡ��C\n",me);
                        return 1;
         
         default:       return 1;
        }
}

