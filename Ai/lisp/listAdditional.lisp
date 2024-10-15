(setq l1 '(10 20 30 40))
(format t "Current List: ~a~%" l1)

(format t "Last Element: ~a [last]~%" (last l1))  ;; Directly display the last element

(when (member 40 l1)                              ;; Use 'when' for a cleaner conditional
  (format t "40 is in the list. [member]~%"))

(format t "Reverse List: ~a [reverse]~%" (reverse l1))  ;; Directly display the reversed list

(format t "Appended List: ~a [append]~%" (append l1 (reverse l1)))  ;; Directly append without storing
