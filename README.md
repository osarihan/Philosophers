Ecole 42 Philosophers

!bonustaki processlerin ortak kullandıkları struct yapısı yanlış!

./philo 5 800 200 200 7 testinde düzgün sonuç vermiyor daha düzgün kod için : https://github.com/nosamanz

Data race nedir?
"A data race occurs when one thread accesses a mutable object while another thread is writing to it." 
source: https://www.avanderlee.com/swift/race-condition-vs-data-race/

Data races ve thread leaks için -g -fsanitize=thread flagini kullanabilirsiniz.
