// qiantang.c �ƥ�G������H
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"�i�����j"+"�Y�s�I�y���{"HIC"��H"HIM"�A�n�p�����A�Ħp�p�^�A�D�`���[�C\n"NOR,users());
                return;
        }
       
                  if( random(100) < 75) {
                        msg =  "\n\t�u���ѪŸU���L���A�Y�s�I�y������R�L�i�C\n" NOR;
                            msg += HIG "\n\t�A���T�Į��D�G�u�ӥi���F...�v\n" NOR;
                        tell_object(room, msg);
                            return;
                }
        
                msg = HIC "\n\t�C�~�K��Q�K�Y�s�I�y����A�D�`�ǮɡA�G�٤�����H�C \n"
                          "\t�C��������{�ɪi�ܬ���A��չG�H�A�Q�����[�C\n";NOR;
        msg += HIC "\t�uť�u�����v�@�}�p���T�L�A����p��@�몺�V���䱲�ӡC\n"
                  "\t�b�����A�����m�ˡA�i�ܸU���A�鰪�V�l�A�U���b�ˡA�u��\n"
                  "\t�y�ܨӶ��ද�A�y�y�r�����C�p�_���O�̡A�s���������z��\n"
                  "\t���R��աI���ҿסy���Y���m��A�n�p�����F��h��p�s\n"
                  "\t���A�Ħp�p�^�z�C�@�ɶ��A���T�I�����A�Ѧa�U�����w�M\n"
                  "\t���h�F�C\n" NOR;
                                   
         msg += HIG "\n\t�A��۬��骺����A�Y���Ү��A��Z�\\�S���F�s����|�C\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 50000 + random(5000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"�Y�s�I�y���{"HIC"��H"HIM"�A�n�p�����A�Ħp�p�^�A�D�`���[�C\n"NOR,users());
}

// �ƥ�Ĳ�o
void trigger_event()
{
        object room;
                
        // ������H
        if (objectp(room = find_object("/open/world1/wilfred/sand/room42")))
                do_bonus(room);
                
}

void create() 
{ 
        seteuid(getuid()); 
}

