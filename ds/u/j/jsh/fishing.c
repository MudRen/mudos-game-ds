#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"�J�������x"NOR);
        set("long", @LONG
�A���i�o�̡A�z�A���n�h���H�b�o�̳����r�I���ɪ��Ǩӿ�
�Ī��ۥs�n�A�o�֩w�S�O���ֳ���F�j���A�ݨ�L�̦����L�L��
�Ī��ˤl�A�A�٦�����ȱo�S�ݪ��A���֮��n�A�������}�l����
(hook)�a�H
LONG );
        set("exits", ([
                  "out" :"/open/world1/wu_sha_town/seacoun42",
                ]));
        set("no_fight", 1);
        set("no_recall", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        
        add_action("do_hook", "hook");
}

int do_hook(string arg)
{

        object me,ob;
        me = this_player();
        ob=new("/obj/money/coin");

        if (me->query("exp") > 9999)
                return notify_fail("�A���g�纡�� . . . �٬O�O�����a�I\n");
        else
                message_vision("$N�j�ۤf�﮳�۳������b�j���Y�W���_���ӡK�K�C\n", me);
        if (me->is_busy())
                return notify_fail ("�A���ʧ@�٨S�����I\n");

                switch(random(10)) {
                        case 0 :
                             message_vision("$N�r�@�����A����F�@��"+ HIR "�j�U��"NOR +"�A���ߡA���ߡC \n\n",me);
                               me->add("exp",20+random(10));
                             me->add("ap",-30);
                           break;
                        case 1 :
                             message_vision("$N�r�@�����A����F"+ CYN "�@�ӯ}��U"NOR +"�A���A���C  \n",me);
                             message_vision(HIW "$N�ΤO����F�}��U�X�} ! ! !  \n\n" NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-220);                           break;
                       
 case 2 :
                             message_vision("$N�ݨ쳽�}�̰ʡA$N���ߤ@�ߡA�r���@�����A$N����F"+ RED "�@����⪺�p�ǿǡC \n"NOR,me);
                             message_vision(HIB "$N�s�n�Į�G���A���C \n\n" NOR,me);
                             me->add("ap",-40); 
                             me->add("exp",-200);                           break;
                        case 3 :
                             message_vision("$N�@�����A����F�@�� "+ HIC "�γ�"NOR +"�A���ߡA���ߡC \n\n",me);
         me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 4 :
                  message_vision("$N�@�����A����F�@��"+ HIG "�V��"NOR +"�A���ߡA���ߡC \n\n",me);
               me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 5 :
                             message_vision("$N�@�����A����F�@��"+HIY" ����"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break; 
case 6 :
                             message_vision("$N�@�����A����F�@��"+HIG" �A��"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 7 :
                             message_vision("$N�@�����A����F�@��"+HIW" �ձa��"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 8 :
                             message_vision("$N�@�����A����F�@��"+HIR" ����"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 9 :
                             message_vision("$N�@�����A����F�@��"+HIW" �k�J��(�p��)"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 10 :
                             message_vision("$N�@�����A����F�@��"+HIB" �"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                        case 11 :
                             message_vision("$N�@�����A����F�@��"+ HIB "�X��"NOR +"�A���ߡA���ߡC \n\n",me);
me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 12 :
                             message_vision("$N�r�@�����A����F"+ HIR "�@���������s��"NOR +"�A���A���C \n",me);
                             message_vision(HIW"$N�ΤO����F�������s���X�} ! ! ! \n\n"NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-300);                           break;
                          case 13 :
message_vision("$N���}�̰ʡA$N�߸̤@��A�r���@�����A$N����F"+ HIM "�@�ӿ��]! \n"NOR,me);
                             message_vision(HIW "$N���|�P�S�H�`�N�A�������������}���]�A�Q���X�̭������C�S�Q�쳺�M�S���A�ϫl����^���̡I \n\n" NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-200);                             ob->move(me);
                           break;
                           case 14 :
                             message_vision("$N�r���@�����A�誺�ӫ�F�A�u�_�F�A���]�F�A�i���A�i���C \n",me);
                             message_vision(HIC "$N���Ѫ��b�߸̤j�|:@#%%#X&�C \n\n" NOR,me);
                             me->add("ap",-35); 
                             me->add("exp",-100);                           break; 
case 15 :
                             message_vision("$N�@�����A����F�@��"+HIW" �k�J��(�j��)"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 16 :
                             message_vision("$N�@�����A����F�@��"+HIW" �k�J��(���j���p -.-#)"NOR +"�A���ߡA���ߡC \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                        default 
:
                             message_vision("$N�@�����A����F�@��"+ HIC "������"NOR +"�A���ߡA���ߡC \n\n",me);
me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                                 }
                         me->start_busy(2);

        return 1;
}

