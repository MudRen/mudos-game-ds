// �Ѧ��r��
// tmr 2006/11/14

#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i, chance;

            obs = all_inventory(room);

        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"�i�����j"+""HIW"�Ѧ��r��"HIM"�E�y����A�_���D�Z�A�L�ƹC�H�ĸr���w�C\n"NOR,users());
                return;
        }
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
          r = random(365);
          if (r < chance )
        {
                msg = HIC "\n\t�uť�F�����n���j���A��Ť�o�|�A�O�H���߯��n�I�A���Y�ݥh�A�u��\n";
                msg += HIC "\t�������Ѧ�Ţ�n�b�h�h���𤧤��A���~���c�C�}�~���y���m�A�����H�I\n" NOR;
                  msg += HIW "\n\t��ӭ��l�ɵ��ϡA�����r���E�e�t�C\n" NOR;
                msg += HIW "\t���y���U�T�d�ءA�ìO�Ȫe���E�ѡC\n" NOR;
                msg += HIG "\n\t�A��۴��檺�r�����m�A���o�@��������Ĥ��w�A�q�����T�⮩��F�Z�Ǫ��D�z�C\n\n" NOR; 


                // �W�[�n���԰����N
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(10) );
                                        obs[i]->add("war_art", 10 + random(10) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
               message("world:world1:vision",HIM"�i�����j"+""HIW"�Ѧ��r��"HIM"�E�y����A�_���D�Z�A�L�ƹC�H�ĸr���w�C\n"NOR,users());
          } else  if (r < 180)   {
                msg = HIC "\n\t�@�}�F���F�����n���ǨӡA�A���Y�@�ݡA�u���������r���˰_�h�h����C\n" NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIW "\t�ݵ۳o���R��"HIC"�r�y"HIW"�A�A���T�P�ġA���ҿסu���y���U�T�d�ءA�ìO�Ȫe���E�ѡv�ڡC\n" NOR; 
                        break;
                case 1:
                        msg += HIW "\t�u��"HIC"�r�y"HIW"�N���@�u�˱�����î�A��զp�i�A�Ѧa�����T��������C\n" NOR; 
                        break;
                default:
                        msg += HIW "\t�u��"HIC"�r�y"HIW"���p���Ȭ��a�@��A����|�q�C\n" NOR; 
                        break;
                }
                msg += HIG "\t�A�[��ۭ��y���U�����r�A�A���ѱo�P�Ħ۵M�y�ƪ��_���A������Z�Ǥ]���F�@�I��|�C\n\n" NOR; 
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) );
                                        obs[i]->add("popularity", 1 + random(3) );
                                        obs[i]->add("war_art", 1 + random(3) );
                                        obs[i]->add("exp", 25000 + random(25000) );
                                }

                tell_object(room, msg);
               message("world:world1:vision",HIM"�i�����j"+""HIW"�Ѧ��r��"HIM"�E�y����A�_���D�Z�A�L�ƹC�H�ĸr���w�C\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t�r�y�����w�F�U�ӡC\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t�r�y�`�O�������W�j���ͶաC\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t�r�y���p�p���y���A�m�m�N�N�A���A�Ҵ��檺�ۮt�ƻ��C\n" NOR;
                        break;

                }
                msg += HIG "\n\t�A�ߤ��j�P����C\n\n" NOR;
                tell_object(room, msg);
        }
}

//�ƥ�Ĳ�o
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/acme/area/pool")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}

