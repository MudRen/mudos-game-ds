#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"�t���w��j��"NOR);
        set("long", @LONG
                      !  !  ! �� �� !  !  !
                       !  I��I��I_�� ��_I��I��I  !
                       I_/|��|��|_�� ��_|��|��|\_I
                    ! /|_/|  |  | �� �� |  |  |\_|\ !
                    I//|  |  |  | �� �� |  |  |  |\\I       
                 ! /|/ |  |  |  | �� �� |  |  |  | \|\ !    
                 I//|  |  |  |  | �� �� |  |  |  |  |\\I    
              ! /|/ |  |  |  |  | �� �� |  |  |  |  | \|\ ! 
              I//|  |  |  |  |  | �� �� |  |  |  |  |  |\\I 
 _!��!��|�I|=/|/ |  |  |  |  |  | �� �� |  |  |  |  |  | \|\=|�I|��!��!_
 _I��I��|�I||/|��|��|��|��|��|��|_�� ��_|��|��|��|��|��|��|\||�I|��I��I_
 -|��|��|�I||-|��|��|��|��|��|������ �򢤢�|��|��|��|��|��|-||�I|��|��|-
  |  |  |�I|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||�I|  |  |
  |  |  |�I|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||�I|  |  |
  |  |  |�I|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||�I|  |  |
  |  |  |�I|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||�I|  |  |
 _|��|��|�I||_|��|��|��|��|��|��|_�� ��_|��|��|��|��|��|��|_||�I|��|��|_
 -|��|��|�I||-|��|��|��|��|��|��|-�� ��-|��|��|��|��|��|��|-||�I|��|��|-
  |  |  |�I|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||�I|  |  |
�t���w�𪺪��f, �j���򳬵�, �q���������i�h, �O�H���ػ����X�������P.
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "northeast": __DIR__"dst2",
            "northwest": __DIR__"dst8",
            ]));
        set("no_clean_up", 0);
    set("outdoors","land");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/poorguard2" : 1,
  __DIR__"npc/poorguard" : 1,
]));
     set("item_desc", ([
"�j��" : "�@���򳬵۪��j��, �W�õL�j��, �ݨӦ��G����Y�}(push), ���D
�O, �Ѫ��D�������]�k���b�W��?\n"
     ]));

        setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "�j��") 
         return 0;
        else {
        message_vision(
        HIY "$N���������F�@�U, �j���K���S�n�����V��ǷƤF�}��...\n\n" NOR ,me);
        message_vision( HIY "$N��B���ͪ����F�i�h, �u��~~�v���@�n�T, �j���b$N����۰����W...\n\n" NOR ,me);
        me->move(__DIR__"dstg1");
        return 1;
             }
}
