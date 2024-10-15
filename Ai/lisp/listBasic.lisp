(setq l1 '(10 20 30 40))
(format t "Current List: ~a~%" l1)

(let ((l2 (cons 0 l1)))  ;; Create l2 within a let block for better scoping
  (format t "New List: ~a [cons]~%" l2)
  (format t "First Element: ~a [car]~%" (car l2))  ;; Directly call car
  (format t "Remaining Element: ~a [cdr]~%" (cdr l2))  ;; Directly call cdr
  (format t "Listed List: ~a [list]~%" (list l1 l2)))  ;; Create l3 inline
