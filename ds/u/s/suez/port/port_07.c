#include <ansi.h>
inherit ROOM;
void create()
{
       set("short","�ĺ��Ĵ���");
        set("long",@LONG
�o�̴N�O�ĺ��Ĵ���F�A�U���U�˪��H�b�o�̦樫�ۡA�U���U�˪���
�~�b�o�̳c��ۡA�o�̬O�s���F��j���̥D�n����f�A�O�F�誺�Ȧ�̲�
�@����쪺�g�a�A�]�O���Ȧ�̳̫ᱵĲ���G�m�C�b��f���F��A�O��
���Ĵ��̨��w�諸�s���u�W���H���C��v�C
LONG 
);
        set("exits",([
            "north":__DIR__"port_06",
            "east":__DIR__"port_10",
            "south":__DIR__"port_08",
                ]));
        set("objects",([
            __DIR__"npc/ad_wm":1,
            __DIR__"npc/waterman":3,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");
        set("light",1);
        setup();

}
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("�@���f����a��F�A�u����f�W�@���V�áC\n",me);
                        return 1;
         case 6:        message_vision("������㻷���W�ǨӤF�C�I�������n�C\n",me);
                        return 1;
         case 5:
         case 4:        message_vision("����̰۵ۡR�u�L�����B����o�I�h�⤰����v\n",me);
                        return 1;
         
         case 3:
         case 2:        message_vision("����̦[�ܵۡR�u�ӳ�I�ӳ�I�n�I�A�L�Ӥ@�I�I�v\n",me);
                        return 1;
         case 1:
         case 0:        message_vision("�a���Ш��������I�I���j�ۡ��C\n",me);
                        return 1;
         
         default:       return 1;
        }
}
