// �j��-�P�H�C�R
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
                message("world:world1:vision",HIM"�i�����j"+"ť�������H���a�V�X�{"HIW"�P�H�C�R"HIM"�A�P�v�ȩ_�A�O�H��i�ҫ�C\n"NOR,users());
                return;
        }

          r = random(300);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
          
          if (r < chance )
        {
                msg = HIW "\n\t�u�����䪺����U�A����ƶh���۪����v�ˬM�b�ﭱ�s�����W�A���C�����_\n"
                           "\t�R�A�C���y���A�P�v�j���C�A������ġG�Ȧt�����A�����p���������ޡA��\n"
                           "\t�馳�t�o���P�H�����A��b�O�֤��D�L�C\n" NOR;
                msg += HIG "\t�A��P�H���C�R�ᦳ�ҷP�A�Z�ǤW�y�ɦ��F�s���⮩�C\n\n" NOR;

                // �W�[�n���԰����N
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť�������H���a�V�X�{"HIW"�P�H�C�R"HIM"�A�P�v�ȩ_�A�O�H��i�ҫ�C\n"NOR,users());
         } else  if (r < 200)   {
                        msg = HIW "\n\t���䪺����U�A���W�����������˼v�X�P�H�����C��D�@���Ȧ��C\n"NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIC "\t�u���ﭱ�s���W�P�v�@�{�Y�L�A���Τ��ӱ��A�O�A�ڥ��L�k�����C\n" NOR;
                        break;
                case 1:
                        msg += HIC "\t�u���s���W�{�L�X�D�P�v�A���G�O�I�i�@�ة_���L�񪺪Z�\\���ǡC\n" NOR;
                        break;
                default:
                        msg += HIC "\t���M������ƶh���۪����v��M�b�ﭱ�s�W�A���P�v�����Y�u�A�A�ڥ��L�k�ݲM�C\n" NOR;
                        break;
                }
                msg += HIG "\t�A����F�P�v���P���A�Z�Ǥ譱�S���F�@����|�C\n\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;

                                        obs[i]->add("popularity", 1 + random(2) );
                                        obs[i]->add("war_art", 1 + random(2) );
                                        obs[i]->add("exp", 10000 + random(10000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť�������H���a�V�X�{"HIW"�P�H�C�R"HIM"�A�P�v�ȩ_�A�O�H��i�ҫ�C\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t�������䪺����ɰ_�A�i�O�@�ζ��ƹL�A�B�\\�F����A�A���e�y�ɤ@�����¡C\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t�A�ؤ�������`���۹ﭱ���ɾ��A�i�b�����p�n�F��A�s�������A�N����B�F���Y��C\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t�]�ߤw�ܡA�i�@�ιο@�p�����h�oŢ�n�ۤѪšA�A�s�ﭱ���s�Y���L�k�ݲM�C\n" NOR;
                        break;
                }
                msg += HIG "\t�A���T�Į��D�G�u��`�t�����ܡA�L�t�s���P�v�I�v\n" NOR;
                tell_object(room, msg);
        }
}

//�ƥ�Ĳ�o
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/tmr/gumu/xuanya")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}


