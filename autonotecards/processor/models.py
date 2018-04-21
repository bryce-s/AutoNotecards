from django.db import models


class PdfPack(models.Model):
    """django model--represents a database"""
    desc = models.CharField(max_length=255, blank=True)
    document = models.FileField(upload_to='documents/')
    uploadTime = models.DateTimeField(auto_now_add=True)
    # note; this will upload to $media_root/documents/YYYY/MM/DD
