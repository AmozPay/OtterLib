FROM ghcr.io/ietf-tools/xml2rfc-dev
COPY . .
RUN pip install rfc2html
RUN ./mmark rfc.md > rfc.xml
RUN xml2rfc rfc.xml
RUN python3 convert_rfc_2html.py
ENTRYPOINT []
CMD ["cat", "/dev/zero"]
