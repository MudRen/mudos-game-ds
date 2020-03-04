// �B��-�y�P�B
// tmr 2006/11/14

#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;
        int chance;

        obs = all_inventory(room);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"�i�����j"+"ť���B��]�ų��{"HIW"�y�P�B"HIM"�A���m�}�ɡA�٬����[�C\n"NOR,users());
                return;
        }

          r = random(400);
          if (r < chance )
         {
                msg = HIC "\n\t�uť�Ѫ��J�M�ǨӤ@�}��ժ������n�A�A����W�a�A�o�{�ƻa�̤w�ŵM�X�{\n"
                           "\t�L�����y�P�C�]�k�p�B���Y�A�W�~���šA�����J�Ѧ������A�S�A�E�_�U�ѤC��\n"
                               "\t���ܡA���©]�Ƴ��S�p�ձޤ@��C�A���T�P�ġA�j�۵M���¡A��u���������C\n" NOR;

                msg += HIG "\t�A�J�Ӫ��[��F�y�P�B�����L�{�A�o�{�䤤�����ܦh�����i�H�ĩ�Z�ǡC\n\n" NOR;

                // �W�[�n���԰����N
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(10) );
                                        obs[i]->add("war_art", 10 + random(10) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť���B��]�ų��{"HIW"�y�P�B"HIM"�A���m�}�ɡA�٬����[�C\n"NOR,users());
        } else  if (r < 200)   {
                msg = HIC "\n\t�uť���B�@�}��ժ������n�A�|�ر�h�A�o�{�����y�P�q���乺�L�A\n"
                          "\t��`�Z�j�e��ӻ��A�ڥ��L�k�ݲM�C\n" NOR;

                msg += HIG "\t�A�[�}�y�P�A��������Z�Ǧ��F�@����|�C\n\n" NOR;
                
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;

                                        obs[i]->add("popularity", 3 + random(3) );
                                        obs[i]->add("war_art", 3 + random(3) );
                                        obs[i]->add("exp", 25000 + random(25000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť���B��]�ų��{"HIW"�y�P�B"HIM"�A���m�}�ɡA�٬����[�C\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t��������@�����G�A���O�y�P�B�N�ܡA�i��`���j���B���h�p�A�o�L�t�o���C\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t��������@�����G�A���O����A����M���h�����A���A���򳣬ݤ��M���C\n" NOR;
                        break;
                }
                msg += HIG "\n\t�A���T�Į��D�G�u�ӥi���F...�v\n" NOR;
                tell_object(room, msg);
        }
}

//�ƥ�Ĳ�o
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/tmr/bagi/ghat6")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}

